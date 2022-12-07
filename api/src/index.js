const express = require('express'),
  app = express(),
  routes = require('./routes.js');

app.use(express.json());
app.use(routes);

const port = process.env.PORT || 3333;

app.listen(port, () => {
  console.log(`Servidor iniciado na porta ${port}`);
})


