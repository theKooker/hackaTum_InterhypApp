
import 'dart:async';
import 'dart:io';
import 'package:stop_watch_timer/stop_watch_timer.dart'; // Import stop_watch_timer


import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class RecordingPage extends StatefulWidget {
  const RecordingPage({Key? key}) : super(key: key);

  @override
  _RecordingPageState createState() => _RecordingPageState();
}

class _RecordingPageState extends State<RecordingPage> {

  final StopWatchTimer _stopWatchTimer = StopWatchTimer();
  bool _startTime = false;
  var button_string = "assets/images/Design_startLifted.png";
  @override
  void dispose() {
    _stopWatchTimer.dispose();
  }
  @override
  Future<void> initState() async {}
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Image.asset("assets/images/Design_BigBackground.png",
              height: MediaQuery.of(context).size.height, fit: BoxFit.fill),
          SingleChildScrollView(
              physics: const NeverScrollableScrollPhysics(),
              child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Center(
                      child: Image.asset("assets/images/Design_shower.png"),
                    ),
                    Center(
                      child: Image.asset(
                          "assets/images/Design_waterStreamSeamless.png",
                          fit: BoxFit.none),
                    ),
                  ])),
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
              Stack(
                children: [
                  Center(
                      child: GestureDetector(
                    onTapDown: (value) {
                      setState(() async {
                        if (button_string ==
                            "assets/images/Design_startLifted.png") {
                          _stopWatchTimer.onExecute.add(StopWatchExecute.start);
                          button_string =
                              "assets/images/Design_startPushed.png";
                            
                        } else {
                          _stopWatchTimer.onExecute.add(StopWatchExecute.reset);
                          button_string = "assets/images/Design_redPushed.png";
                        }
                        _startTime = !_startTime;
                      });
                    },
                    onTapUp: (value) {
                      setState(() {
                        if (button_string ==
                            "assets/images/Design_startPushed.png") {
                          button_string = "assets/images/Design_redLifted.png";
                        } else {
                          button_string =
                              "assets/images/Design_startLifted.png";
                        }
                      });
                    },
                    child: Column(
                      children: [
                        Stack(
                          children: [
                            Image.asset(button_string),
                            if (_startTime)
                              Positioned.fill(
                                  child: Align(
                                      alignment: Alignment.center,
                                      child: StreamBuilder<int>(
                                          stream: _stopWatchTimer.rawTime,
                                          initialData:
                                              _stopWatchTimer.rawTime.value,
                                          builder: (context, snapshot) {
                                            final value = snapshot.data;
                                            final displayTime =
                                                StopWatchTimer.getDisplayTime(
                                                    value!,
                                                    hours: false,
                                                    milliSecond: false);
                                            return Text(
                                              displayTime,
                                              style: const TextStyle(
                                                  fontSize: 50,
                                                  fontWeight: FontWeight.bold,
                                                  color: Colors.white),
                                            );
                                          })))
                          ],
                        )
                      ],
                    ),
                  )),
                ],
              )
            ],
          )
        ],
      ),
    );
  }
}
