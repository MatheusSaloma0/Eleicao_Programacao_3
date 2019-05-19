package pkg_01;

import java.util.Comparator;

/**
 * Classe que implementa atributos e métodos de um Candidato em uma eleição.
 */
public class Candidato implements Comparator<Candidato> {
	private String nome; // Nome do candidato.
	private Partido partido; // Partido do candidato.
	private int votos_recebidos; // Identifica o numero de votos recebidos pelo candidato.
	private boolean eleito; // True significa que foi eleito.
							// False significa que nao foi eleito.

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Partido getPartido() {
		return partido;
	}

	public void setPartido(Partido partido) {
		this.partido = partido;
	}

	public int getVotos_recebidos() {
		return votos_recebidos;
	}

	public void setVotos_recebidos(int votos_recebidos) {
		this.votos_recebidos = votos_recebidos;
	}

	public boolean isEleito() {
		return eleito;
	}

	public void setEleito(boolean eleito) {
		this.eleito = eleito;
	}

	@Override
	public int compare(Candidato a, Candidato b) {
		return a.getVotos_recebidos() - b.getVotos_recebidos();
	}

	@Override
	public String toString() {
		if (this.getPartido().getColigacao().getPartidos().size() > 1) {
			return this.getNome() + " (" + this.getPartido().getNome() + ", " + this.getVotos_recebidos() + " votos)"
					+ " - " + this.getPartido().getColigacao();
		} else {
			return this.getNome() + " (" + this.getPartido().getNome() + ", " + this.getVotos_recebidos() + " votos)";
		}
	}

}
