
Chained inheritance: Device → Computer → Laptop
A class inherits from a class that has itself inherited from another, so a Laptop is a Computer, which is a Device.
Each level adds its own members: Device has brand and price, Computer adds ramGB and processor, and Laptop adds batteryHours and touchscreen.
Laptop gets everything from both parents, so lp.powerOn() (from Device) and lp.runProgram() (from Computer) both work.
protected data is usable by the children but hidden from main().
Constructors run Device → Computer → Laptop, passing values up through initializer lists.
Benefit: code reuse, with common code written once.
Polymorphism: Payment → MobileMoney / Card / Cash
The same call, pay(), behaves differently depending on the object.
Payment declares virtual pay(), and each child overrides it: 1% fee for mobile money, 2.5% for card, no fee for cash.
A base-class pointer or reference (Payment*, const Payment&) can hold any child.
virtual makes C++ pick the version at runtime through the vtable (late binding). Without it, the pointer type decides and every call runs the base version.
Benefit: new payment types can be added without changing existing code.