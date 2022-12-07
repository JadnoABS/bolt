const express = require('express'),
  router = express.Router(),
  db = require('./app/models');


const UserController = require('./app/controllers/UserController');
const SessionController = require('./app/controllers/SessionController');
const TrackController = require('./app/controllers/TrackController');


router.get('/', (req, res) => {
  res.json({message: "TESTE123"});
});

router.post('/user', UserController.create);
router.get('/session', SessionController.authenticate);

router.post('/track', TrackController.create);
router.get('/track', TrackController.list);

module.exports = router;
