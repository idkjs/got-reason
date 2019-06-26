Utils.requireCSS("./CharacterDetail.css");
// Utils.requireCSS("./CharacterList.css");
open CharacterDetailQuery;
[@react.component]
let make = (~id) => {
  // let id = selectedCharacter;
     Js.log2("HANDLE_CLICK_ID",id);

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
             | None => "Select a Person" |> React.string
             | Some(character) =>
              //  <Detail
              //    character
              //    select={_e => {
              //      setSelectedCharacter(character##id);
              //      %raw
              //      "window.scrollTo(0, 0)";
              //    }}
              //  />
              <div className="CharacterDetail">
                <CharacterListItem character />
              </div>
             }
           }}
        </div>
      }
    </CharacterDetailQuery>;
  // | None =>
  //   <>
  //     <h2> {"Character Detail" |> React.string} </h2>
  //     <div> {"Please select a character" |> React.string} </div>
  //   </>
};