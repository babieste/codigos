let itens = [
  {
    nome: "Banana",
    valor: 2.1,
    quantidade: 1
  },
  {
    nome: "Sabonete",
    valor: 1.3,
    quantidade: 3
  },
  {
    nome: "Doritos",
    valor: 4.7,
    quantidade: 2
  },
  {
    nome: "Pão",
    valor: 0.38,
    quantidade: 10
  },
  {
    nome: "Leite",
    valor: 2.34,
    quantidade: 3
  },
  {
    nome: "Ovos",
    valor: 0.42,
    quantidade: 12
  }
];

let quantidadeProdutos = 0;
let valorTotal = 0;

for(let item of itens){
  quantidadeProdutos += item.quantidade;
  valorTotal += item.valor;
}

console.log(`O valor total da lista de compras é de R$ ${valorTotal} e a quantidade de produtos é ${quantidadeProdutos}`);