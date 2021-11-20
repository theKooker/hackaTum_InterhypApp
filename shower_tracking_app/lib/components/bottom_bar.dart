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
            decoration: BoxDecoration(
              color: Colors.blue.shade100,
              borderRadius: const BorderRadius.all(
                Radius.circular(30),
              ),
              boxShadow: <BoxShadow>[
                BoxShadow(
                    blurRadius: 8, offset: Offset.zero, color: Colors.blue.shade200)
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
                      child: SizedBox(
                        width: 60,
                        child: Column(
                          mainAxisSize: MainAxisSize.max,
                          children: <Widget>[
                            Expanded(
                              child: Icon(
                                widget.items[i].icon,
                                color: i == widget.index
                                    ? widget.items[i].color
                                    : widget.items[i].inactiveColor,
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
    this.color = Colors.indigo,
    this.inactiveColor = Colors.indigoAccent
  });

  final IconData icon;
  final String label;
  final Color color;
  final Color inactiveColor;
}
