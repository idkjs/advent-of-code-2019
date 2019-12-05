[%%debugger.chrome];
let test_values = [2, 4, 4, 5, 99, 0];
let rec compute = (input_values, input_value_index) => {
  let process_this_value = input_values->List.nth(input_value_index);
  if (process_this_value != 99) {
    compute(input_values, input_value_index + 1);
  } else {
    0;
  };
};
let divideBy3 = mass => mass /. 3.;
/* convert a float back to int thereby cutting of any decimal remainder */
let roundDown = mass => mass->int_of_float;
/* subtract two from the result*/
let subtractTwo = int => int - 2;
let rec convert = value => {
  let converted = value |> float |> divideBy3 |> roundDown |> subtractTwo;
  Js.log2("converted", converted);
  let result = converted >= 0 ? convert(converted) : ();
  result;
};
module BL = Belt.List;
let test_values: BL.t(int) = [2, 4, 4, 5, 99, 0];
// open Belt.List;
let rec convertListHd = list => {
  list->Js.log;
  let initial = 0;
  Js.log2("intial", initial);
  let add = value => initial + value;
  let valueToAdd = value =>
    value |> float |> divideBy3 |> roundDown |> subtractTwo |> add;
  let listLength = list->BL.length;
  switch (list->BL.headExn) {
  | [] => ()
  | [head, ...rest] => valueToAdd(head) |> ignore
  };
  convertListHd(list->BL.tailExn);
};
let main = () => {
  Js.log("Hello, Day 2!");
  compute(test_values, 0) |> Js.log;
  convert(99)->Js.log;
  convertListHd(test_values);
};