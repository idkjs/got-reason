Utils.requireCSS("./CharacterDetail.css");
open CharacterDetailQuery;
[@react.component]
let make = (~selectedCharacter, ~onChangeCharacter) => {
  switch (selectedCharacter) {
  | Some(id) =>
    let characterDetailQuery = CharacterDetail.make(~id, ());
    <CharacterDetailQuery variables=characterDetailQuery##variables>
      ...{({result}) =>
        <div className="CharacterDetail">
          {switch (result) {
           | Error(e) =>
             Js.log(e);
             "Something Went Wrong" |> React.string;
           | Loading => "Loading" |> React.string
           | Data(response) =>
             switch (response##getCharacter) {
             | None => "No Character Data" |> React.string
             | Some(character) => <Detail character onChangeCharacter />
             }
           }}
        </div>
      }
    </CharacterDetailQuery>;
  | None =>
    <div className="CharacterDetail">
      <h2> {"Character Detail" |> React.string} </h2>
      <div> {"Please select a character" |> React.string} </div>
    </div>
  };
};