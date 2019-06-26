Utils.requireCSS("./CharacterList.css");
open CharacterListQuery;
[@react.component]
let make = (~onChangeCharacter) => {
  <div className="CharacterList">
    <h2> {"All Characters" |> React.string} </h2>
    <CharacterListQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {React.string("Loading")} </div>
        | Error(error) => <div> {React.string(error##message)} </div>
        | Data(response) =>
          let characters = response##getCharacters;
          <ul>
            {React.array(
               Belt.Array.map(characters, character =>
                 <CharacterListItem character onChangeCharacter />
               ),
             )}
          </ul>;
        }
      }
    </CharacterListQuery>
  </div>;
};