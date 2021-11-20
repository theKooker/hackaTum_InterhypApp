import 'package:flutter/widgets.dart';

class History extends StatefulWidget{
  @override
  State<StatefulWidget> createState() => _HistoryState();
}

class _HistoryState extends State<History>{
  @override
  Widget build(BuildContext context) {
    return Container(
      height: MediaQuery.of(context).size.height,
      child: Center(child: Text("History")),
    );
  }
}