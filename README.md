
# Passageiros:

#### Passageiro compra bilhete (FEITO)
 - Voo::sellBilhete()
 - Voo::sellBilheteGrupo()
#### Faz check-in & Despacha as malas (FEITO)
- Passageiro::checkIn()
#### Vai para o avião (FEITO)
- Passageiro::getIntoPlane() and Voo:addPassageiro()

# Transporte de malas:

#### Associar carrinho a aviao (FEITO) (CARRINHOS LIMITADOS??? EXTRA)
- CarrinhoTransporte::setAviao()
#### Carregar malas para o carrinho (FEITO)
- Passageiro::checkIn()
#### Descarregar malas do carrinho (FEITO)
- No addMala verificar se carrinho está cheio e descarregar no avião

# Avião:

#### Chega ao Aeroporto (FEITO)
- Aviao::aterrar()
- Aeroporto::addAviao() (neste metodo é feita a atribuicao do carrinho)
#### Descarrega as malas do avião (FEITO)
- Aviao::descarregarMalas()
#### Fazer servicos (FEITO)
- Aviao::addServico()
- Aviao::processServico()
#### Atualiza o plano de voo
- Aviao::addVoo()
#### Carrega as novas malas se o carrinho estiver cheio
#### Carregar malas restantes e Partir

# Serviços:

#### Escolher funcionario com menos ocupacao (EXTRA)
#### Fazer o serviço (FEITO)
- Aviao::processService()

# Transporte:

#### Horas de chegada/saida no Aeroporto
- Transporte::getHoraChegada()

# Aeroporto:

#### Chegada & Partida de Aviões
- Atributo aviões
- add e removeAviao()
#### Gestão dos CarrinhosTransporte
- Atributo carrinhos
- Associar Avião carrinho