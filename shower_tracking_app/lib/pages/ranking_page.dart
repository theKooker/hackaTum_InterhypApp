import 'package:flutter/material.dart';

class RankingPage extends StatefulWidget {
  const RankingPage({Key? key}) : super(key: key);

  @override
  _RankingPageState createState() => _RankingPageState();
}

class _RankingPageState extends State<RankingPage> {
  final _textStyle = const TextStyle(
    fontSize: 20,
    color: Colors.white,
  );

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.indigo,
      body: SafeArea(
        child: Expanded(
          child: SingleChildScrollView(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const Padding(
                  padding: EdgeInsets.all(20),
                  child: Text('Ranking',
                      style: TextStyle(
                          fontSize: 40,
                          fontWeight: FontWeight.bold,
                          color: Colors.white)),
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
        _row(5, "Alex"),
        _row(6, "Alex"),
        _row(7, "Alex"),
        _row(8, "Alex"),
        _row(9, "Alex"),
        _row(10, "Alex"),
        _row(11, "Alex"),
        const SizedBox(
          height: 120,
          width: double.infinity,
        ),
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
          Text(
            name,
            style: _textStyle,
          ),
        ],
      ),
    );
  }

  Widget _row(int num, String name) {
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
                child: Center(
                  child: Text(
                    num.toString(),
                    style: _textStyle,
                  ),
                ),
                height: 50,
                width: 50,
              ),
            ),
          ),
          Text(
            name,
            style: _textStyle,
          ),
        ],
      ),
    );
  }
}
