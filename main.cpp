#include "pubsub_publisher.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <project-id> <topic-id> <message>\n";
        return 1;
    }

    std::string const project_id = argv[1];
    std::string const topic_id = argv[2];
    std::string const message = argv[3];

    PubSubPublisher publisher(project_id, topic_id);

    publisher.PublishMessage(message);
    publisher.Shutdown();

    return 0;
}

