package pkg_01;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class Testador {

	/**
	 * Realiza a leitura do arquivo de entrada e armazena todos os dados referentes
	 * à eleição.
	 *
	 * @param f   Nome do arquivo (.csv) dado como entrada.
	 * @param cod Tipo de codificação a ser utilizada.
	 * @return Objeto representando a eleição.
	 */
	public static Eleicao lerArquivo(String f, String cod) {

		try (BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(f), cod))) {
			Scanner s1 = new Scanner(in);

			String line = s1.nextLine(); // Ignora o cabeçalho do arquivo de entrada.

			String aux;

			List<Candidato> candidatos = new LinkedList<Candidato>();
			Map<String, Partido> partidos = new HashMap<String, Partido>();
			List<Coligacao> coligacoes = new LinkedList<Coligacao>();

			Locale l = new Locale("pt", "BR");

			while (s1.hasNextLine()) {
				line = s1.nextLine();
				Scanner s2 = new Scanner(line);
				s2.useDelimiter(";");
				s2.useLocale(l);
				Candidato v = new Candidato();

				if (s2.next().charAt(0) == '*')
					v.setEleito(true);
				else
					v.setEleito(false);

				s2.nextInt(); // Ignora o número do candidato.

				v.setNome(s2.next());

				aux = s2.next(); // String referente ao partido e coligação.
				Scanner s3 = new Scanner(aux);
				s3.useDelimiter(" -");

				String nomePartido = s3.next(); // String referente ao nome do partido.
				if (partidos.containsKey(nomePartido) == false) {
					Partido p = new Partido(nomePartido);
					partidos.put(nomePartido, p);
					p.insere(v);
				}

				v.setPartido(partidos.get(nomePartido)); // Define o partido do candidato.
				partidos.get(nomePartido).insere(v); // Adiciona o candidato ao partido.

				// Se o partido deste candidato ainda não estiver em alguma coligação.
				if (v.getPartido().getColigacao() == null) {
					if (s3.hasNext()) { // Se o partido estiver em uma coligação.
						s3.skip(" - ");
						s3.useDelimiter(" / ");
						Coligacao c = new Coligacao();
						while (s3.hasNext()) { // Enquanto tiver partidos para serem adicionados na coligação.
							nomePartido = s3.next();

							if (partidos.containsKey(nomePartido) == false) { // Verifica se o partido já existe.
								Partido p = new Partido(nomePartido); // Se o partido não existe, ele é criado.
								partidos.put(nomePartido, p);
								p.setColigacao(c);
							}
							if (c.contem(partidos.get(nomePartido)) == false) { // Verifica se o partido já está na
																				// coligação.
								Partido p = partidos.get(nomePartido);
								c.insere(p); // Se o partido ainda não estiver na coligação, ele é adicionado.
								p.setColigacao(c);
							}

						}
						coligacoes.add(c); // Adiciona a coligação que acabou de ser criada no conjunto de coligações.

					} else { // Se o partido não estiver em uma coligação, é criada uma coligação que contém
							 // apenas o próprio partido.
						Coligacao c = new Coligacao();
						v.getPartido().setColigacao(c);
						c.insere(v.getPartido());
						coligacoes.add(c); // Adiciona a coligação que acabou de ser criada no conjunto de coligações.
					}
				}

				s3.close();

				v.setVotos_recebidos(s2.nextInt());

				s2.next();// Ignora a porcentagem de votos validos.

				candidatos.add(v); //Adiciona o candidato v ao conjunto de candidatos.

				s2.close();
			}

			s1.close();

			// Copiamos os valores dos partidos para uma lista.
			List<Partido> partidos2 = new LinkedList<Partido>(partidos.values());

			Eleicao e = new Eleicao(candidatos, partidos2, coligacoes);

			return e;

		} catch (IOException e) {
			System.out.println("Erro na abertura do arquivo.");
			return null;
		}
	}

	public static void main(String[] args) {

		Eleicao e = lerArquivo(args[0], args[1]);

		if (e != null) {
			System.out.println("Número de vagas: " + e.numVagas() + "\n");
			System.out.println(e.candidatosEleitos());
			System.out.println(e.candidatosMaisVotados());
			System.out.println(e.votacaoMajoritaria());
			System.out.println(e.beneficiadosSistProp());
			System.out.println(e.dadosDasColigacoes());
			System.out.println(e.dadosDosPartidos());
		}

	}

}
