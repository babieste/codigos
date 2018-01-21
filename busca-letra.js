let frase = "Três pratos de trigo para três tigres tristes";
let letra_procurada = 'r';
let contador = 0;


for(let letra of frase){
	if (letra == letra_procurada){
		contador++;
	}
}

console.log(`A frase "${frase}" possui ${contador} letras ${letra_procurada}`);
