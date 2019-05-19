package pkg_01;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Classe que implementa atributos e métodos relativos a uma Eleição.
 */
public class Eleicao {
	private List<Candidato> candidatos = new LinkedList<Candidato>();
	private List<Partido> partidos = new LinkedList<Partido>();
	private List<Coligacao> coligacoes = new LinkedList<Coligacao>();

	public Eleicao(List<Candidato> candidatos, List<Partido> partidos2, List<Coligacao> coligacoes) {
		Collections.sort(candidatos, Collections.reverseOrder(new Candidato()));
		this.candidatos = candidatos;

		Collections.sort(partidos2, Collections.reverseOrder(new Partido()));
		this.partidos = partidos2;

		Collections.sort(coligacoes, Collections.reverseOrder(new Coligacao()));
		this.coligacoes = coligacoes;
	}

	public List<Candidato> getCandidatos() {
		return candidatos;
	}

	public void setCandidatos(List<Candidato> candidatos) {
		this.candidatos = candidatos;
	}

	public List<Partido> getPartidos() {
		return partidos;
	}

	public void setPartidos(List<Partido> partidos) {
		this.partidos = partidos;
	}

	public List<Coligacao> getColigacoes() {
		return coligacoes;
	}

	public void setColigacoes(List<Coligacao> coligacoes) {
		this.coligacoes = coligacoes;
	}

	/**
	 * Conta quantos candidatos foram eleitos, representando a quantidade de vagas.
	 *
	 * @return O numero de vagas da eleição.
	 */
	public int numVagas() {
		int n_vagas = 0;

		for (Candidato v : this.candidatos) {
			if (v.isEleito()) {
				n_vagas++;
			}
		}

		return n_vagas;
	}

	/**
	 * Realiza o somatório de todos os votos recebidos pelos candidatos.
	 *
	 * @return A quantidade total de votos da eleição.
	 */
	public int totalVotosNominais() {
		int n_votos = 0;

		for (Candidato v : this.candidatos) {
			n_votos += v.getVotos_recebidos();
		}

		return n_votos;
	}

	/**
	 * Reúne informações de todos os partidos, com exceção dos partidos sem candidatos.
	 *
	 * @return Texto contendo dados de todos os partidos.
	 */
	public String dadosDosPartidos() {
		String result = "Votação (nominal) dos partidos e número de candidatos eleitos:\n";

		int i = 1;
		int votos_totais = 0;
		
		for (Partido p : this.partidos) {
			if(p.getCandidatos().size() > 0) {
				result += i + " - " + p.dadosDoPartido() + "\n";
				votos_totais += p.votosTotais();
				i++;
			}
			
		}
		result += "\nTotal de votos nominais: " + votos_totais + "\n";

		return result;
	}

	/**
	 * Reúne informacoes de todas as coligações.
	 *
	 * @return Texto contendo dados das coligações.
	 */
	public String dadosDasColigacoes() {
		String result = "Votação (nominal) das coligações e número de candidatos eleitos:\n";

		int i = 1;

		for (Coligacao c : this.coligacoes) {
			result += i + " - " + c.dadosDaColigacao() + "\n";
			i++;
		}

		return result;
	}

	/**
	 * Reúne informações sobre os candidatos eleitos.
	 *
	 * @return Texto contendo dados dos candidatos eleitos.
	 */
	public String candidatosEleitos() {
		String result = "Vereadores eleitos:\n";
		int i = 1;
		for (Candidato v : this.candidatos) {
			if (v.isEleito()) {
				result += i + " - " + v + "\n";
				i++;
			}
		}
		return result;
	}

	/**
	 * Reúne informações sobre os candidatos mais votados (em ordem decrescente de
	 * votacao e respeitando numero de vagas).
	 *
	 * @return Texto contendo dados dos candidatos mais votados.
	 */
	public String candidatosMaisVotados() {
		String result = "Candidatos mais votados"
				+ "(em ordem decrescente de votação e respeitando número de vagas):\n";

		for (int i = 0; i < this.numVagas(); i++) {
			result += (i + 1) + " - " + this.getCandidatos().get(i).toString() + "\n";
		}

		return result;
	}

	/**
	 * Reúne informações sobre os candidatos que teriam sido eleitos se a votação
	 * fosse majoritária, e não foram eleitos.
	 *
	 * @return Frase contendo informacoes sobre os candidatos que seriam eleitos
	 *         caso a votacao fosse majoritaria.
	 */
	public String votacaoMajoritaria() {
		String result = "Teriam sido eleitos se a votação fosse majoritária, e não foram"
				+ " eleitos:\n(com sua posição no ranking de mais votados)\n";
		String line1 = candidatosMaisVotados();
		String line2 = candidatosEleitos();

		Scanner s1 = new Scanner(line1);
		s1.useDelimiter("\n");
		Scanner s2 = new Scanner(line2);
		s2.useDelimiter("\n");

		s1.next(); // Ignora o cabecalho da string
		s2.next(); // Ignora o cabecalho da string

		String aux;

		// Verificamos os candidatos que estao dentre os mais votados.
		// Se eles nao estiverem na string que representa os candidatos eleitos,
		// armazenamos suas informacoes, pois com isso, sabemos que ele esta
		// entre os que seriam eleitos caso a votacao fosse majoritaria.
		while (s1.hasNext()) {
			line1 = s1.next();
			aux = line1.substring(line1.indexOf("-") + 2, line1.length());

			if (line2.contains(aux) == false) {
				result += line1 + "\n";
			}
		}

		s1.close();
		s2.close();
		return result;
	}

	/**
	 * Reúne informações sobre os candidatos que se beneficiaram do sistema
	 * proporcional.
	 *
	 * @return Texto contendo informações sobre os candidatos que se beneficiaram do
	 *         sistema proporcional.
	 */
	public String beneficiadosSistProp() {
		String result = "Eleitos, que se beneficiaram do sistema proporcional:\n"
				+ "(com sua posição no ranking de mais votados)\n";

		for (int i = this.numVagas(); i < this.getCandidatos().size(); i++) {
			if (this.getCandidatos().get(i).isEleito()) {
				result += (i + 1) + " - " + this.getCandidatos().get(i).toString() + "\n";
			}
		}

		return result;
	}
}
