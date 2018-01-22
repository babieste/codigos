module.exports.retornarPar = (numeros, pares) => {
    for(numero of numeros){
        if(numero % 2 == 0){
            pares.push(numero);
        }
    }
    return pares;
}