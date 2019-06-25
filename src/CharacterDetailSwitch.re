Utils.requireCSS("./CharacterDetail.css");
open CharacterDetailQuery;
[@react.component]
let make = (~term, ~onChangeCharacter) => {
  switch (term) {
  | Some(term) =>
    let characterDetailQuery = CharacterDetail.make(~id=term, ());
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
             | Some(character) =>
             <Detail character onChangeCharacter />
            //  <div className="CharacterDetail">
            //     <CharacterListItem character />
            //   </div>
             }
           }
           }
        </div>
      }
    </CharacterDetailQuery>;
  | None =>
    <>
      <h2> {"Character Detail" |> React.string} </h2>
      <div> {"Please select a character" |> React.string} </div>
    </>;
  };
};