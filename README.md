# Eleicao_Programacao_3
Trabalhos realizados na disciplina de Programação III (Java,C++)

Sistema para processar os dados disponibilizados pela Justiça Eleitoral referentes à votação de
vereadores em um município.

O arquivo de divulgação contendo obter os resultados da votação nominal em vereadores de um município
segue o seguinte formato:
- A primeira coluna identifica um número de sequência, sendo precedido por asterisco (‘*’) quando o
candidato foi eleito, e por cerquilha (‘#’) se o candidato não teve seus votos validados devido à sua
situação jurídica ou à do seu partido.
- A segunda coluna identifica o número do candidato.
- A terceira coluna identifica a sigla do partido, e, se houver, a coligação com outros partidos. (A sigla
do partido é separada da coligação com um hífen (‘-’), e os partidos de uma coligação são separados
por uma barra (‘/’).)
- A quarta coluna identifica o número de votos recebidos pelo candidato.
- A quinta coluna indica a porcentagem dos votos válidos recebidos pelo candidato.

O programa lê os dados em um arquivo de divulgação (cujo nome é passado na linha
de comando) e gera diversos relatórios na saída padrão:
- Número de vagas;
- Candidatos eleitos (sempre indicando partido, número de votos e coligação, se houver)
- Candidatos mais votados dentro do número de vagas;
- Candidatos não eleitos e que seriam eleitos se a votação fosse majoritária;
- Candidatos eleitos no sistema proporcional vigente, e que não seriam eleitos se a votação fosse
majoritária, isto é, pelo número de votos apenas que um candidato recebe diretamente;
- Votos totalizados por coligação ou partido (quando um partido não estiver em coligação), número de
candidatos eleitos;
- Votos totalizados por partido, número de candidatos eleitos;
- Total de votos nominais.
