const db = require('../models'),
  jwt = require('jsonwebtoken'),
  bcrypt = require('bcrypt');


class SessionController {


  async authenticate(req, res) {

    const { username, password } = req.body;

    const user = await db.User.findOne({ where: { username: username } });

    if (!user) {
      return res.status(404).json({ error: "Usuário não encontrado com esse username" });
    }

    const validPassword = await bcrypt.compare(password, user.password);

    if (!validPassword) return res.status(400).json({ error: "Senha incorreta" });

    const token = jwt.sign({ id: user.id }, process.env.JWT_SECRET);

    res.status(200).json({ token });

  }
}


module.exports = new SessionController();
