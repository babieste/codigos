let argumentos = process.argv; //Guarda na variável "argumentos" os valores passados pelo terminal.
let numeros = [];


for(let i = 2; i < argumentos.length; i++){
    numeros.push(Number(argumentos[i])); //Passa de fato os valores passados no terminal para um vetor de números.
}



console.log(numeros);