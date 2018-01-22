let valores = ['maçã', 'banana', 'pera', '7'];
let escolha = [];



for(let i = 0; i < 3; i++){
	let x = Math.floor((Math.random() * 4) + 1); //Número aleatório entre 1 e 4
	escolha[i] = valores[x-1];
}

if(escolha[0] == escolha[1] && escolha[1] == escolha[2]){
	console.log(`Os valores sorteados foram ${escolha[0]}, ${escolha[1]} e ${escolha[2]}. Parabéns, você foi sorteado!`);
}
else {
	console.log(`Os valores sorteados foram ${escolha[0]}, ${escolha[1]} e ${escolha[2]}. Você foi não sorteado!`);

}
