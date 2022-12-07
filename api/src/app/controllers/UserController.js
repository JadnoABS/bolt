const db = require('../models');

class UserController {

  async create(req, res) {
    const {
      username,
      email,
      password,
      age,
      height,
      weight
    } = req.body;

    try {
      db.User.create({
        username,
        email,
        password,
        age,
        height,
        weight
      });

      res.sendStatus(200);
    } catch(err) {
      console.log(err);
      res.sendStatus(500);
    }
  }
}

module.exports = new UserController();
