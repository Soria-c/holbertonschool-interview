#!/usr/bin/node
const { get } = require('request');
const id = process.argv[2];
const baseUrl = `https://swapi-api.hbtn.io/api/films/${id}`;

const getCharacter = (character) => new Promise((resolve, reject) => {
  get(character, (err, data) => {
    if (err) {
      reject(err);
      return;
    }

    const { name } = JSON.parse(data.body);
    resolve(name);
  });
});

get(baseUrl, (err, data) => {
  if (err) console.error(err);
  const { characters } = JSON.parse(data.body);

  const promises = characters.map(character => getCharacter(character));

  Promise.all(promises).then(names => names.forEach(name => console.log(name)));
});
