Utils.requireCSS("./CharacterDetail.css");

[@react.component]
let make = (~character, ~onChangeCharacter) => {
  let handleClick = id => {
    onChangeCharacter(id);
  };

  let renderItem = (~label: string, ~item) => {
    switch (item) {
    | Some(item) =>
      <div> <strong> label->React.string </strong> item->React.string </div>
    | None => React.null
    };
  };

  let renderListItem = (~label: string, ~items: option('a)) => {
    switch (items) {
    | Some(items) =>
      <div>
        <strong> label->React.string </strong>
        {React.array(Belt.Array.map(items, i => i ++ " " |> React.string))}
        {" " |> React.string}
      </div>
    | None => React.null
    };
  };

  let renderCharacter = (~label: string, ~c) => {
    switch (c) {
    | Some(c) =>
      let name = c##name;
      let id = c##id;
      <div>
        <strong> label->React.string </strong>
        <a href="#" onClick={_e => handleClick(id)}> name->React.string </a>
      </div>;
    | None => React.null
    };
  };
  <>
    <h2> {character##name |> React.string} </h2>
    {switch (character##allegiances) {
     | Some(allegiances) =>
       let lastIndex = Belt.Array.length(allegiances);
        Js.log2("LENGTH: ", lastIndex);
       let withConcat =
         Belt.Array.map(allegiances, a => a##name) |> Belt.List.fromArray(_);
       let withConcatI =
         allegiances->Belt.Array.mapWithIndex((i, a) => (i, a))
         |> Belt.List.fromArray(_);
       let lastItem = withConcatI->List.length - 1;
       let renderItem = (index, item) =>
         {<div> {item##name |> React.string} </div>};
       let renderItemWithComma = (index, item) =>
         {<div> {item##name |> React.string} {", " |> React.string} </div>};
       Js.log(string_of_int(lastItem));
       let filterFx = (index, item) =>
         switch (index === lastIndex - 1) {
         | true => renderItem(index, item)
         | _ => renderItemWithComma(index, item)
         };
       //  let result = withConcatI Belt.List.map(i,a)|> {
       //        i === lastItem ? () : String.concat(", ")
       //  } |> Belt.List.toArray;
       <div>
          <strong> {"Loyal to: " |> React.string} </strong> {allegiances->Belt.Array.mapWithIndex(filterFx)->React.array} </div>;
         //  {React.array(
         //     Belt.Array.map(allegiances, a =>
         //       <div>
         //         {a##name |> React.string}
         //         {" " |> React.string}
         //       </div>
         //     ),
         //   )}
     | None => React.null
     }}
    {renderItem("Culture: ", character##culture)}
    {renderItem("Played by: ", character##playedBy)}
    {renderListItem("Titles: ", character##titles)}
    {renderListItem("Aliases: ", character##aliases)}
    {renderItem("Born: ", character##born)}
    {renderItem("Died: ", character##died)}
    {renderItem("Culture: ", character##culture)}
    {renderCharacter("Father: ", character##father)}
    {renderCharacter("Mother: ", character##mother)}
    {renderCharacter("Spouse: ", character##spouse)}
    {switch (character##children) {
     | Some(children) =>
       switch (Belt.Array.length(children)) {
       | 0 => React.null
       | _ =>
         <div>
           <strong> {"Children" |> React.string} </strong>
           <br />
           {React.array(
              Belt.Array.map(children, c =>
                <>
                  <a href="#" onClick={_e => handleClick(c##id)}>
                    {c##name->React.string}
                  </a>
                  {" " |> React.string}
                </>
              ),
            )}
         </div>
       }
     | None => React.null
     }}
    {Belt.Array.length(character##appearedIn) > 0
       ? <div>
           <strong> {"TV Seasons: " |> React.string} </strong>
           <br />
           {Belt.Array.map(character##appearedIn, season =>
              <> {season##name->React.string} {" " |> React.string} </>
            )
            |> React.array}
         </div>
       : React.null}
    {switch (character##books) {
     | Some(books) =>
       <div>
         <strong> {"Books: " |> React.string} </strong>
         <br />
         {React.array(
            Belt.Array.map(books, c =>
              <> {c##name->React.string} {" " |> React.string} </>
            ),
          )}
       </div>
     | None => React.null
     }}
  </>;
};