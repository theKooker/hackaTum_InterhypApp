import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/test_page.dart';

import 'components/bottom_bar.dart';

class RouterPage extends StatefulWidget {
  const RouterPage({
    Key? key,
  }) : super(key: key);

  @override
  State<RouterPage> createState() => _RouterPageState();
}

class _RouterPageState extends State<RouterPage> {
  int _currentIndex = 0;

  @override
  Widget build(BuildContext context) {
    return _bottomNavPagination();
  }

  Scaffold _bottomNavPagination() {
    return Scaffold(
      body: Stack(children: [
        TestPage(),
        BottomBar(
          index: _currentIndex,
          onChange: (value) {
            setState(() {
              _currentIndex = value;
            });
          },
          items: <BottomBarItem>[
            BottomBarItem(Icons.play_arrow_outlined,
                label: "Record"), //Recording
            BottomBarItem(Icons.list_alt_outlined), //Ranking
            BottomBarItem(Icons.history_outlined), //History
            BottomBarItem(Icons.account_circle_outlined), //Account
          ],
        ),
      ]),
    );
  }
}
