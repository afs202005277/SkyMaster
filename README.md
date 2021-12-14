
#Passageiros:

####Passageiro compra bilhete FEITO
 - Voo::sellBilhete()
 - Voo::sellBilheteGrupo()
####Faz check-in & Despacha as malas
####Vai para o avião
- classe Voo/Avião

#Transporte de malas:

####Associar carrinho a aviao (CARRINHOS LIMITADOS??? EXTRA)
####Carregar malas para o carrinho
####Descarregar malas do carrinho
- No addMala verificar se carrinho está cheio e descarregar no avião

#Avião:

####Chega ao Aeroporto
####Descarrega as malas do avião
#### Fazer servicos (FEITO)
- Aviao::addServico()
- Aviao::processServico()
####Atualiza o plano de voo
- Aviao::addVoo()
####Carrega as novas malas se o carrinho estiver cheio
####Carregar malas restantes e Partir

#Serviços:

####Escolher funcionario com menos ocupacao (EXTRA)
####Fazer o serviço
- Aviao::processService()

#Transporte:

####Horas de chegada/saida no Aeroporto
- Transporte::getHoraChegada()

#Aeroporto:

####Chegada & Partida de Aviões
- Atributo aviões
- add e removeAviao()
####Gestão dos CarrinhosTransporte
- Atributo carrinhos
- Associar Avião carrinho