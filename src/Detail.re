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
  let renderComma = (arr, index) =>
    index !== Belt.Array.length(arr) - 1
      ? {
        ", " |> React.string;
      }
      : React.null;
  // let renderListItem = (~label: string, ~items) => {
  //   switch (items) {
  //   | Some(items) =>
  //     <div>
  //       <strong> label->React.string </strong>
  //       {items->Belt.Array.mapWithIndex((i, item) => item |> React.string |> {renderComma(items, i)}
  //        |> React.array})
  //       |> {renderComma(items, i)}
  //        |> React.array}
  //     </div>
  //   | None => React.null
  //   };
  // };
  let renderListItem = (~label: string, ~items) => {
    switch (items) {
    | Some(items) =>
      let arr = items;
      <div>
        <strong> label->React.string </strong>
        {Belt.Array.mapWithIndex(arr, (index, item) =>
           <>
             item->React.string
             {renderComma(arr, index)}
             {" " |> React.string}
           </>
         )
         |> React.array}
      </div>;
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

  Js.log2("CHARACTER_ALIASES: ", character##aliases);
  let renderAliases = {
    switch (character##aliases) {
    | Some(aliases) =>
      let arr = aliases;
      <div>
        <strong> {"Aliases: " |> React.string} </strong>
        {Belt.Array.mapWithIndex(arr, (index, a) =>
           <>
             a->React.string
             {renderComma(arr, index)}
             {" " |> React.string}
           </>
         )
         |> React.array}
      </div>;
    | None => React.null
    };
  };
  let renderTitles = {
    switch (character##titles) {
    | Some(titles) =>
      let arr = titles;
      <div>
        <strong> {"Titles: " |> React.string} </strong>
        {Belt.Array.mapWithIndex(arr, (index, a) =>
           <>
             a->React.string
             {renderComma(arr, index)}
             {" " |> React.string}
           </>
         )
         |> React.array}
      </div>;
    | None => React.null
    };
  };
  let checkIfLastItem = (arr, index) =>
    switch (index === Belt.Array.length(arr) - 1) {
    | true => true
    | _ => false
    };
  <>
    <h2> {character##name |> React.string} </h2>
    // {renderAllegiances}
    {switch (character##allegiances) {
     | Some(allegiances) =>
       switch (Belt.Array.length(allegiances)) {
       | 0 => React.null
       | _ =>
         let renderLast = item => item##name |> React.string;
         let renderItemWithComma = item => item##name ++ ", " |> React.string;
         let renderFunc = (index, item) =>
           checkIfLastItem(allegiances, index)
             ? renderLast(item) : renderItemWithComma(item);
         <div>
           <strong> {"Loyal to: " |> React.string} </strong>
           {allegiances->Belt.Array.mapWithIndex(renderFunc)->React.array}
         </div>;
       }
     | None => React.null
     }}
    {renderItem(~label="Culture: ", ~item=character##culture)}
    {renderItem(~label="Played by: ", ~item=character##playedBy)}
    // {renderTitles}
    {renderListItem(~label="Titles: ", ~items=character##titles)}
    {renderListItem(~label="Aliases: ", ~items=character##aliases)}
    // renderAliases
    {renderItem(~label="Born: ", ~item=character##born)}
    {renderItem(~label="Died: ", ~item=character##died)}
    {renderItem(~label="Culture: ", ~item=character##culture)}
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
       ? {
         let arr = character##appearedIn;

         <div>
           <strong> {"TV Seasons: " |> React.string} </strong>
           <br />
           {arr->Belt.Array.mapWithIndex((index, season) =>
              <>
                {season##name->React.string}
                {renderComma(arr, index)}
                {" " |> React.string}
              </>
            )
            |> React.array}
         </div>;
       }
       : React.null}
    {switch (character##books) {
     | Some(books) =>
       let arr = books;
       <div>
         <strong> {"Books: " |> React.string} </strong>
         <br />
         {books->Belt.Array.mapWithIndex((index, book) =>
            <>
              {book##name->React.string}
              {renderComma(arr, index)}
              {" " |> React.string}
            </>
          )
          |> React.array}
       </div>;
     | None => React.null
     }}
  </>;
};