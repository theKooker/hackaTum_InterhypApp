import 'package:flutter/material.dart';

class BottomBar extends StatefulWidget {
  const BottomBar({Key? key, required this.items, required this.index, required this.onChange}) : super(key: key);

  final List<BottomBarItem> items;
  final int index;
  final Function(int) onChange;

  @override
  _BottomBarState createState() => _BottomBarState();
}

class _BottomBarState extends State<BottomBar> {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Align(
        alignment: Alignment.bottomCenter,
        child: Padding(
          padding: const EdgeInsets.fromLTRB(20, 0, 20, 15),
          child: Container(
            height: 60,
            decoration: const BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.all(
                Radius.circular(30),
              ),
              boxShadow: <BoxShadow>[
                BoxShadow(
                    blurRadius: 5, offset: Offset.zero, color: Colors.grey)
              ],
            ),
            child: Row(
              mainAxisSize: MainAxisSize.min,
              children: <Widget>[
                const SizedBox(
                  width: 30,
                ),
                for (int i = 0; i < widget.items.length; i++)
                  InkWell(
                    onTap: () => widget.onChange(i),
                    child: Padding(
                      padding: const EdgeInsets.fromLTRB(5, 0, 5, 0),
                      child: Container(
                        width: 60,
                        child: Column(
                          mainAxisSize: MainAxisSize.max,
                          children: <Widget>[
                            Expanded(
                              child: Icon(
                                widget.items[i].icon,
                                color: i == widget.index
                                    ? widget.items[i].color
                                    : null,
                                size: i == widget.index ? 35 : 20,
                              ),
                            ),
                            if (i == widget.index)
                              Container(
                                width: 60,
                                height: 3,
                                decoration: BoxDecoration(
                                  color: widget.items[i].color,
                                  borderRadius: const BorderRadius.only(
                                    topLeft: Radius.circular(3),
                                    topRight: Radius.circular(3),
                                  ),
                                ),
                              ),
                          ],
                        ),
                      ),
                    ),
                  ),
                const SizedBox(
                  width: 30,
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}

class BottomBarItem {
  BottomBarItem(
    this.icon, {
    this.label = "",
    this.color = Colors.red,
  });

  final IconData icon;
  final String label;
  final Color color;
}
