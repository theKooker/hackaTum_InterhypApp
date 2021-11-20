import 'package:flutter/material.dart';

class Ranking extends StatefulWidget{
  @override
  State<StatefulWidget> createState() => _RankingState();
}

class _RankingState extends State<Ranking>{
  @override
  Widget build(BuildContext context) {
    return Container(
      height: MediaQuery.of(context).size.height,
      child: Center(child: const Text('Ranking')),
    );
  }
}