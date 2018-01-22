//var linhaDoVetor = ["0", "0", "0", "0", "0", "0"];
var linhaDoVetor = [];
var n = prompt("Digite o tamanho da escada");
for( var i = 0; i < n ; i++){
	linhaDoVetor.push("0");
}
var linha = 0;
var str = "";

	for (var i = 0; i < n; i++ ) {
    	linhaDoVetor.shift();
        linhaDoVetor.push("#");
        str += linhaDoVetor.join("");
        str += "\n";
        //alert(linhaDoVetor);
    }

alert(str);
