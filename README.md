# Atv6-sw-Producer_Consumer
  O programa recebe 4 variáveis para executar, um número de produtores ( P ), </br>
o número de consumidores ( C ), um limite para a produção de valores ( N ) e por fim, </br>
um valor para determinar o tamanho do buffer circular ( b_size ). Após o sistema </br>
ler os valores, ele cria duas listas para armazenar as threads que serão, respectivamente, </br>
os produtores, que geram os dados e os adiciona no buffer, e consumidores, que coletam </br>
os dados e os retiram do buffer. </br>

## Installation
```bash
$ git clone https://github.com/Luizfpbp/Atv6-sw-Producer_Consumer.git
$ cd Atv6-sw-Producer_Consumer
```

## Commands
```bash
$ make        # Compila o arquivo c       
$ make run    # Executa o arquivo c
$ make clean  # Limpa o binario gerado do arquivo c
```
