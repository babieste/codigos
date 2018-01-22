let argumentos = process.argv;
let notas = [];

for(i = 2; i < argumentos.length; i++){
    notas.push(Number(argumentos[i]));
}

const calcularMedia = (notas) => {
    let total = 0;
    for(nota of notas){
        total += nota;
    }

    return total/notas.length;

}

if(calcularMedia(notas) >= 6){
    console.log(`O aluno foi aprovado com a nota ${calcularMedia(notas)}`);
} else {
    console.log(`O aluno foi reprovado com a nota ${calcularMedia(notas)}`);
}
