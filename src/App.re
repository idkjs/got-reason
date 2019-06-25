Utils.requireCSS("./App.css");

[@react.component]
let make = () => {
    let (term, setTerm) = React.useState(() => None);

    let handleCitySelected = city => {
        Js.log2("handleCitySelected_APP",city);
              setTerm(_ => Some(city));
        Js.log2("handleCitySelected_APP_TERM",term);
      };
  <div className="App">
    <header className="App-header">
      <h1> {"An app of the seven kingdoms" |> React.string} </h1>
    </header>
    <div className="Character-wrapper">
          <CharacterListCB onChangeCharacter=handleCitySelected />
          <CharacterDetailSwitch term onChangeCharacter=handleCitySelected />
      // {switch(term) {
      // | Some(term) => <CharacterDetailCB id=term />
      // | None =>
      //    <>
      //     <h2> {"Character Detail" |> React.string} </h2>
      //     <div> {"Please select a character" |> React.string} </div>
      //   </>
      // }}
      // <CharacterDetail selectedCharacter />
      // <CharacterDetail selectedCharacter setSelectedCharacter />
      // <CharacterList />

    </div>
  </div>;
};