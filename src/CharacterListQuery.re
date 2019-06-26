module CharacterList = [%graphql
  {|
      query CharacterList {
        getCharacters(sortDirection: ASC) {
          id
          name
          playedBy
          culture
          allegiances {
            name
          }
          isAlive
      }
    }
  |}
];

module CharacterListQuery = ReasonApollo.CreateQuery(CharacterList);