# Bolt
O Bolt é uma tornozeleira inteligente que coleta dados de uma corrida e auxilia o atleta mostrando o seu desempenho. Acompanha também uma palmilha geradora de energia.
É uma alternativa para atletas amadores e/ou de baixa renda que buscam uma solução barata para medir o seu desempenho nos seus treinos e corridas.

# Contrução
O Bolt consiste em duas partes, a tornozeleira inteligente, a qual conta com um microcontrolador ESP32 e um acelerômetro (inserir modelo do acelerometro), e a palmilha geradora de energia, a qual possui um circuito de pastilhas piezoelétricas e uma bateria recarregável.

## Tornozeleira Inteligente

## Palmilha geradora
A palmilha do Bolt possui um circuito formado por 6 pastilhas piezoelétricas ligadas em paralelo e conectadas a uma ponte de diodo, a saída desse circuito leva corrente a uma bateria recarregável a qual alimenta a tornozeleira.


# Visualização e armazenamento dos dados
Os dados coletados pelo Bolt são transmitidos para o aparelho celular do atleta via bluetooth e poderão ser vistos por meio do aplicativo do Bolt. Assim que os dados chegam no app, eles são salvos na conta do atleta por meio da API com a qual o app se comunica.
<img src="images/circuito2.jpg" alt="drawing" width="400"/>

<h3>Materiais e Métodos: </h3>

Para o desenvolvimento do projeto da tornozeleira<b> Bolt </b>, com medição de aceleração, foi necessário a utilização do tecido Neoprene, a escolha foi devido às propriedades do tecido como impermeabilidade, proteção térmica, resistência e maleabilidade. Propriedades essas, que são essenciais para o desenvolvimento eficaz da tornozeleira, já que a mesma precisa de um revestimento impermeável e resistente, por exemplo, para proteção dos componentes elétricos internos (Ex: microcontrolador, acelerômetro). Além disso, por se tratar de um produto desenvolvido para pessoas que praticam esportes, o tecido de escolha precisa ter propriedade de regulação térmica para não prejudicar o usuário na durante o uso. 
Para o fechamento da tornozeleira foi escolhido o velcro por possibilitar um ajuste ao tornozelo mais eficiente e se adaptar melhor a variação de tamanhos. 
Para o desenvolvimento da palmilha com a funcionalidade de gerar energia, foi usado uma placa de PVC para dar sustentabilidade às pastilhas  piezoelétricas e uma parte do circuito, o material foi escolhido por ter a rigidez necessária para o apoio das pastilhas mas ao mesmo tempo  ainda ter a  flexibilidade necessária para  não causar machucados ou incômodo durante o uso. 
Para revestir a placa de PVC foram cortadas 4 camadas no formato de palmilhas de tênis Tam 42 e dispostas uma sobre a outra para formar uma palmilha única com a placa de pvc interna. 

<img src="images/tornozeleira.jpeg" alt="drawing" width="400"/>
<img src="images/tornozeleira2.jpeg" alt="drawing" width="400"/>

<h4>Precificação do Acelerômetro e Palmilha </h4>

<p> Preço ( Acelerômetro) 

Acelerômetro : R$15,00 <br>
Microcontrolador: 44,00 <br>
Velcro: 1,00 <br>
Neoprene: 8,00 <br>

<b>Preço total: 68,00 </b> <br>

Preço Palmilha <br>

Pastilhas Piezoelétricas: 6,00<br>
EVA: 1,00<br>
Chapa PVC: 10,00<br>
Powerbank: 20,00<br>
   <b> Preço Total : 37,00</b>
</p>


# Considerações finais

Tanto a tornozeleira quanto a palmilha precisam de ajustes e adaptações para que se tornem mais comerciais.

Pontos de melhoria:
- Case de plástico para melhor acomodação do acelerômetro  e do microcontrolador.
- Bateria deve ser menor para maior conforto do usuário final.
- Palmilha deve ser dupla e menos grossa para melhorar a usabilidade.
- Acelerômetro precisa passar por mais calibrações para obter dados mais precisos.

# Referências
- http://repositorio.aee.edu.br/bitstream/aee/1476/1/GERAÇÃO DE ENERGIA ATRAVÉS DA PIEZOELETRECIDADE.pdf
- https://www.youtube.com/watch?v=Uc4CD1aEFwE
- https://www.instructables.com/Electricity-Generating-Footwear/
- https://razoesparaacreditar.com/tenis-gera-energia-limpa-ba/
