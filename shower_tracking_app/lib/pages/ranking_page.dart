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

  List<String> ranking() {
    //list of random names
    final names = [ "Ezar Baines", "Ingolf Papp", "Naoko Stuber", "Bárbara Hightower", "Nuh Delany", "Preeti Garry", "T'Challa Panosyan", "Helen Greer", "Clothildis John"];
    return names;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.indigo,
      body: Stack(
        children: [
          SafeArea(
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
      
          Positioned(
            bottom: -50,
            right: -50,
            child: Image.asset("assets/images/LogInPage_Bubble2.png", width: 250,),
          ),
      
          Positioned(
            top: -20,
            right: -50,
            child: Image.asset("assets/images/LogInPage_Bubble1.png", width: 250,),
          ),
        ],
      ),
    );
  }

  Widget _first3() {
    var names = ranking();

    return Column(
      children: [
        _rowFirst3(60, "assets/images/Design_1.png", names[0]),
        _rowFirst3(50, "assets/images/Design_2.png", names[1]),
        _rowFirst3(40, "assets/images/Design_3.png", names[2]),
        
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
