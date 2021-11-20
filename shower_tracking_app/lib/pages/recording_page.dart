import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class RecordingPage extends StatefulWidget {
  const RecordingPage({Key? key}) : super(key: key);

  @override
  _RecordingPageState createState() => _RecordingPageState();
}

class _RecordingPageState extends State<RecordingPage> {
  var button_string = "assets/images/Design_startLifted.png";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Image.asset("assets/images/Design_BigBackground.png",
              height: MediaQuery.of(context).size.height, fit: BoxFit.fill),
          Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
            Center(
              child: Image.asset("assets/images/Design_shower.png"),
            ),
            Center(
              child: Image.asset("assets/images/Design_waterStreamSeamless.png",
                  fit: BoxFit.none),
            ),
          ]),
          Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                  child: GestureDetector(
                child: Image.asset(button_string),
                onTapDown: (value) {
                  setState(() {
                    if (button_string ==
                        "assets/images/Design_startLifted.png") {
                      button_string = "assets/images/Design_startPushed.png";
                    } else {
                      button_string = "assets/images/Design_redPushed.png";
                    }
                  });
                },
                onTapUp: (value) {
                  setState(() {
                    if (button_string ==
                        "assets/images/Design_startPushed.png") {
                      button_string = "assets/images/Design_redLifted.png";
                    } else {
                      button_string = "assets/images/Design_startLifted.png";
                    }
                  });
                },
              )),
            ],
          )
        ],
      ),
    );
  }
}
