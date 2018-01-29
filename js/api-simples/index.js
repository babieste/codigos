const express = require('express'); //Importa a biblioteca Express
const app = express(); //Instancia a biblioteca em uma variável, para ser chamada durante o programa.

app.listen(3000, () => {  //Função listen, parâmetros(porta a ser escutada, função callback)
    console.log(`Servidor rodando. Acesse em http://localhost:3000`);
});

//Criando a primeira rota:
app.get('/', (req, res) => {
    console.log(`Agora estou usando nodemon para acessar minha rota padrão /`);
    res.send(`Hello World!`);
});

app.get('/clientes', (req, res) => {
    console.log(`Acessei a rota de /clientes`);
    res.send(`Estou na rota de clientes`);
});
