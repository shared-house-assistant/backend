[View me in a monospaced font]

This is just conceptual - by dan

A camera device is a pi connected to a camera, capable of connecting to the internet.

                      ___________        __________       ____________
[Camera Device]<---->|           |      |          |     |            |
                     |           |      |          |     |            |
[Camera Device]<---->| Pi Server |<---->| Database |<--->| AI Server? |
                     |           |      |          |     |            |
[Camera Device]<---->|___________|      |__________|     |____________|
                                           ^
                   ____________            |
[Web Client]<---->|            |           |
                  | Web Server |<----------/
[Web Client]<---->|____________|


AI Server could just be integrated into Pi or Web Server, but the idea would be
to have optional fields in the database for things like predictions of schedules, and maybe connect the lighting devices directly to that?
