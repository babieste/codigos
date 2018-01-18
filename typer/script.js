let p = document.querySelector('p');

let contador = 0;
let frase = 'Bem-vindo à minha página!';

function digitar(){
	if(contador < frase.length){
		p.innerHTML = p.innerHTML + frase[contador];
		contador++;
	}
}

setInterval(digitar, 50);