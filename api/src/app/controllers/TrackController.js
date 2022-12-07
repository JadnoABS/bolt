const db = require('../models'),
  jwt = require('jsonwebtoken');

class Track {

  async create(req, res) {
    const {
      distancia,
      velocmedia,
      kcal
    } = req.body;

    const token = req.get('token');

    const decoded = await jwt.verify(token, process.env.JWT_SECRET);
    const user = await db.User.findOne({ where: { id: decoded.id } });

    if(!user)
      return res.send(404).json({"erro": "Usuario nao existe"});

    let run;
    try {
      run = await db.Track.create({
        distancia,
        velocmedia,
        kcal,
        user_id: user.id
      });

      if(run)
        res.sendStatus(200).json({"message": "Corrida registrada"});
      else throw new Error("Erro no registro de corrida");
    } catch(err) {
      console.log(err);
      if(!run)
        return res.sendStatus(500).json("erro no servidor");
    }
  }


  async list(req, res) {

    const token = req.get("token");

    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    const user = await db.User.findOne({ where: { id: decoded.id } });

    try {
      if(user) {
        const runs = await db.Track.findAll({ where: { user_id: user.id } });

        return res.status(200).json(runs);
      }

      return res.status(404).json({ "error": "Usuario nao encontrado" });
    } catch(err) {
      console.log(err);
      return res.status(500).json({"error": err});
    }
  }
}


module.exports = new Track();
