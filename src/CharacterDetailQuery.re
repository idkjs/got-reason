module CharacterDetail = [%graphql
  {|
      query CharacterDetail($id: ID!) {
    getCharacter(characterId: $id) {
      id
      name
    playedBy
    culture
    titles
    aliases
    born
    died
    allegiances {
      name
    }
    isAlive
    father {
      id
      name
    }
    mother {
      id
      name
    }
    spouse {
      id
      name
    }
    children {
      id
      name
    }
    appearedIn {
      name
    }

    books {
      id
      name
    }
    }
  }
  |}
];

module CharacterDetailQuery = ReasonApollo.CreateQuery(CharacterDetail);