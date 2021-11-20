import 'package:flutter/material.dart';

class RankingPage extends StatefulWidget {
  const RankingPage({Key? key}) : super(key: key);

  @override
  _RankingPageState createState() => _RankingPageState();
}

class _RankingPageState extends State<RankingPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.indigo,
      body: SafeArea(
        child: Expanded(
          child: SingleChildScrollView(
            child: Column(
              children: [
                const Padding(
                  padding: EdgeInsets.all(20),
                  child: Text('Ranking'),
                ),
                _first3(),
              ],
            ),
          ),
        ),
      ),
    );
  }

  Widget _first3() {
    return Column(
      children: [
        _rowFirst3(60, "assets/images/Design_1.png", "Paul Köhler"),
        _rowFirst3(50, "assets/images/Design_2.png", "Mohamed "),
        _rowFirst3(40, "assets/images/Design_3.png", "Dyllan"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
        _row(4, "Alex"),
      ],
    );
  }

  Widget _rowFirst3(double height, String img, String name) {
    return Container(
      width: double.infinity,
      margin: const EdgeInsets.only(left: 10, right: 10, bottom: 5, top: 5),
      padding: const EdgeInsets.all(10),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(20),
        color: Colors.blue.shade800,
      ),
      child: Row(
        mainAxisSize: MainAxisSize.min,
        children: [
          Container(
            margin: const EdgeInsets.only(right: 20),
            width: 80,
            child: Align(
              alignment: Alignment.centerLeft,
              child: Container(
                padding: const EdgeInsets.all(10),
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(1000),
                  color: Colors.blue.shade700,
                ),
                child: Image.asset(
                  img,
                  height: height,
                ),
              ),
            ),
          ),
          Text(name),
        ],
      ),
    );
  }

  Widget _row(int num, String name){
    return Container(
      width: double.infinity,
      margin: const EdgeInsets.only(left: 10, right: 10, bottom: 5, top: 5),
      padding: const EdgeInsets.all(10),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(20),
        color: Colors.blue.shade800,
      ),
      child: Row(
        mainAxisSize: MainAxisSize.min,
        children: [
          Container(
            margin: const EdgeInsets.only(right: 20),
            width: 80,
            child: Align(
              alignment: Alignment.centerLeft,
              child: Container(
                padding: const EdgeInsets.all(10),
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(1000),
                  color: Colors.blue.shade700,
                ),
                child: Text(num.toString()),
              ),
            ),
          ),
          Text(name),
        ],
      ),
    );
  }
}
