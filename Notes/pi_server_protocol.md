Pis will store a token. This will identify them to the server and will
associate the pi with a house and room (after setup). This will prevent needing to
re setup the system in case of power failure, broken connection etc.

Problem: how do we get token onto pi?

A solution: {
give the pis set ID numbers. Put a physical label/NFC tag/QR code on the pi/camera device. This label should represent the ID.

When connecting to the server for the first time, PI sends ID number. Server goes into "pairing mode" where it waits for someone connected to the web client to enter this ID (hence the physical label). After timeout, server closes connection.
}

After this, server knows which house/account the pi is associated with.

conceptual protocol (assumes secure connection, authenticated server(+ pi?)
Pi -> Server: token || ID (make tokens start with 1, IDs with 0)
Server -> Pi: Ack (&& token if new)
Pi -> Server: <data> (Repeat)


