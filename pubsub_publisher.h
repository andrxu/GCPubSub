#ifndef PUBSUB_PUBLISHER_H
#define PUBSUB_PUBLISHER_H

#include "google/cloud/pubsub/publisher.h"
#include <string>
#include <iostream>

class PubSubPublisher {
public:
    PubSubPublisher(std::string const& project_id, std::string const& topic_id);

    void PublishMessage(std::string const& data);

    void Shutdown();

private:
    google::cloud::pubsub::Publisher publisher_;
};

#endif // PUBSUB_PUBLISHER_H
