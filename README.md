## Alunos:
- Clarissa de Lucena Nóbrega
- Ismael Marinho Rocha
- Marcelo Ribeiro da Silva
---
# SISTEMA DE CAPTAÇÃO DE ÁGUA PARA SMART CAMPUS BASEADA EM IOT 

## INTRODUÇÃO
Em conjunto com o desenvolvimento da tecnologia, a necessidade de proteger e preservar os recursos naturais também aumentou, por isso surgem diversas áreas para fomento e evolução de sistemas embarcados e IoT, que ajudam a controlar e gerenciar melhor estes recursos.
O projeto visa trazer uma possível solução para Smart Campus e automação residencial com a finalidade de  melhorar ou até mesmo implantar a captação de água para reutilizar e assim preservar os recursos hídricos.
Inicialmente a proposta é utilizar microcontroladores, sensores e atuadores para ativar e desativar a captação de água.
## MOTIVAÇÃO
Supondo que temos um Ginásio com 60 metros de comprimento e 40 metros de largura, assim totalizando uma área total de 2400 metros quadrados, como mostra a Figura 1. Se em uma hora chover uma chuva média de 10mm/h então a área poderá captar cerca de 24 metros cúbicos de água ou 24000 litros. E isto é apenas um ginásio fictício, a quantidade de água que pode ser captada em Campus reais é muito maior.

![Figura 1. Área de um ginásio fictício.](/images/fig1.PNG)

Figura 1. Área de um ginásio fictício

## REQUISITOS FUNCIONAIS
- Verificação da ocorrência de chuvas;
- Medição da vazão de água;
- Verificar quando a caixa d’água estiver cheia;

## REQUISITOS NÃO FUNCIONAIS
- O sistema não deve permitir que haja desperdício de água;
- O sistema deve esperar alguns segundos de chuva antes de abrir a comporta para limpar o telhado;
- Identificação dos atributos por meio de sensores.
- Sinalização.

## ARQUITETURA DO PROJETO
A figura 2 mostra a arquitetura do sistema proposto envolvendo o Arduino Uno como controlador central, conectado a diversos componentes. O sistema realiza a leitura contínua da vazão de água, exibindo os dados no display LCD. Quando o sensor de chuva detecta precipitação e a cisterna não está cheia, o buzzer é acionado com alertas sonoros e a válvula solenóide abre a comporta, permitindo o fluxo de água. O sistema opera até que a cisterna esteja cheia; nesse momento, o buzzer soa novamente, a válvula é fechada, e o funcionamento é encerrado. Se parar de chover, o sistema fecha a comporta e atualiza o display, garantindo o controle automático do fluxo de água.

![Figura 2.  Arquitetura do projeto proposto.](/images/fig2.PNG)

Figura 2.  Arquitetura do projeto proposto.

## FUNCIONAMENTO DA POC
A Prova de Conceito (PoC) é composta por um sistema automatizado que gerencia o fluxo de água em uma cisterna, integrando sensores e atuadores. Abaixo, descrevemos o funcionamento detalhado do sistema:

- Leitura do Sensor de Fluxo: O sensor de fluxo realiza medições da vazão de água a cada 500 milissegundos, exibindo continuamente o resultado em litros por minuto (L/min) na tela de um display LCD. Essa informação permite monitorar em tempo real a quantidade de água que está sendo captada.
- Ação em Caso de Chuva: Quando a chuva está presente, o sistema verifica a umidade através de um sensor específico. Se a leitura do sensor de umidade for inferior a 200 e a cisterna não estiver cheia, o sistema realiza as seguintes ações:
  - Aciona um buzzer, emitindo cinco toques curtos, com intervalos de 100 milissegundos entre cada toque;
  - Abre a comporta de captação de água;
  - Exibe a mensagem “Comporta aberta” no display LCD, indicando que a captação de água está em andamento.

- Encerramento do Funcionamento: O funcionamento do sistema é interrompido quando a cisterna atinge a sua capacidade máxima. Nesse caso, o sistema executa as seguintes ações:
  - Emite três toques no buzzer, com intervalos de 200 milissegundos entre cada um, sinalizando que a cisterna está cheia;
  - Exibe a mensagem “Está cheio” no LCD, informando sobre a situação da cisterna;
  - Fecha-se a comporta e em seguida a mensagem “Comporta fechada” é mostrada no display LCD.

- Interrupção por Parada de Chuva: Caso a chuva cesse, o sistema também fecha a comporta e exibindo a mensagem “Comporta fechada” no LCD, independentemente do estado da cisterna.

## MATERIAIS E VALORES
A tabela 1 abaixo sugere sites para a compra dos componentes.

Tabela 1. Sites para a compra dos componentes
| Descrição do item        | Valor previsto | Site sugerido                                                                                       |
|--------------------------|----------------|-----------------------------------------------------------------------------------------------------|
| 1 Arduino Uno             | R$ 89,90       | [smartkits](https://www.smartkits.com.br/placa-uno-r3-cabo-usb-arduino-compativel)            |
| 1 Sensor de chuva         | R$ 8,90        | [smartkits](https://www.smartkits.com.br/sensor-de-chuva)                                     |
| 1 Sensor de fluxo         | R$ 28,90       | [smartkits](https://www.smartkits.com.br/sensor-de-fluxo-de-agua-yf-s201-12)                  |
| 1 Válvula solenóide       | R$ 49,90       | [smartkits](https://www.smartkits.com.br/valvula-de-vazao-solenoide-220v-1-2-polegada)        |
| 1 Buzzer contínuo         | R$ 10,90       | [smartkits](https://www.smartkits.com.br/buzzer-continuo-sfm-20b-3-a-24v)                     |
| 1 Display                 | R$ 37,90       | [smartkits](https://www.smartkits.com.br/display-oled-128x64-0-96-i2c-azul)                   |
| 1 Relé                    | R$ 5,90        | [smartkits](https://www.smartkits.com.br/rele-songle-5v-10a)                                  |




## PLANEJAMENTO DE MONTAGEM E TESTES DA POC
Antes de realizarmos a montagem da POC, utilizamos a ferramenta EasyEDA para elaborar o esquema elétrico do projeto (Figura 3). Foi utilizado um sensor de umidade do solo, devido a indisponibilidade do sensor de chuva, mas o princípio de funcionamento é o mesmo. Enfrentamos um problema com a válvula solenóide, que, além de apresentar uma vazão baixa, possui uma malha que dificulta a passagem de água, mas fizemos os testes dos componentes e todos estão funcionando corretamente. A Figura 4 mostra a POC construída.


![Figura 3. Esquema elétrico da POC.](/images/fig2.PNG)

Figura 3. Esquema elétrico da POC.

![Figura 4. Imagem da POC construída.](/images/fig3.PNG)

Figura 4. Imagem da POC construída

## CONCLUSÕES
Apesar dos pequenos desafios encontrados durante o desenvolvimento, como a baixa vazão da válvula solenóide, o sistema funcionou conforme esperado, cumprindo todas as funções propostas. A prova de conceito (PoC) mostrou a viabilidade do projeto, evidenciando a capacidade de automação e controle preciso do fluxo de água para enchimento da cisterna. O uso da ferramenta EasyEDA para o desenvolvimento do esquema elétrico foi fundamental para a organização do projeto, e os testes realizados garantiram o funcionamento adequado dos componentes. Como proposta para trabalhos futuros, pode ser feito o uso de transceptores wi-fi e bluetooth para fazer a conexão com a internet das coisas.




