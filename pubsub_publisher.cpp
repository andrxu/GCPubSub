#include "pubsub_publisher.h"

namespace pubsub = google::cloud::pubsub;

PubSubPublisher::PubSubPublisher(std::string const& project_id, std::string const& topic_id)
    : publisher_(pubsub::MakePublisherConnection(pubsub::Topic(project_id, topic_id))) {}

void PubSubPublisher::PublishMessage(std::string const& data) {
    auto future = publisher_.Publish(pubsub::MessageBuilder{}.SetData(data).Build());

    auto result = future.get();
    if (!result) {
        std::cerr << "Publish failed: " << result.status() << "\n";
    } else {
        std::cout << "Message ID: " << *result << "\n";
    }
}

void PubSubPublisher::Shutdown() {
    publisher_.Flush();
}
