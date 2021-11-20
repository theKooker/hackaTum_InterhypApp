import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/test_page.dart';

import 'components/bottom_bar.dart';

class RouterPage extends StatelessWidget {
  const RouterPage({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(children: [
        TestPage(),
        BottomBar(
            index: 0,
            onChange: (value) {},
            items: <BottomBarItem>[
              BottomBarItem(Icons.play_arrow_outlined, label: "Record"), //Recording
              BottomBarItem(Icons.list_alt_outlined), //Ranking
              BottomBarItem(Icons.history_outlined), //History
              BottomBarItem(Icons.account_circle_outlined), //Account
            ],
          ),
      ]),
    );
  }
}