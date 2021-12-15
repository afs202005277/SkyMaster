
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
#### Atualiza o plano de voo (FEITO)
- Aviao::addVoo()
- Aviao::removeFromPlanoVoo()??
- Aviao::viajar()
#### Carregar malas restantes e Partir (FEITO)
- Aviao::viajar()

# Serviços:

#### Escolher funcionario com menos ocupacao (EXTRA)
#### Fazer o serviço (FEITO)
- Aviao::processService()

# Transporte:

#### Horas de chegada/saida no Aeroporto (FEITO)
- Transporte::getHoraChegada()
- Transporte::getHoraPartida()

# Aeroporto:

#### Chegada & Partida de Aviões (FEITO)
- Aeroporto::addAviao()
- Aeroporto::removeAviao()
#### Gestão dos CarrinhosTransporte (FEITO)
- Aeroporto::addAviao()