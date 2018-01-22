let lista = [10, 20, 50, 100, 1];
let ok = true;


for(let item of lista){
	if(lista[item] < lista[item+1]){
		ok = false;
	}
}

if(ok == false){
	console.log(`A lista não é ordenada.`);
}
else {
	console.log(`A lista é ordenada.`);
}
