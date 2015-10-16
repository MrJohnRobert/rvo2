
#ifndef RVO2_POSE_SUBSCRIBER_H
#define RVO2_POSE_SUBSCRIBER_H

#define EPS 0.00001

using namespace std;

class PoseSubscriber {

    protected:
        RVO::RVOSimulator *sim;
        ros::NodeHandle n;
        ros::Subscriber sub;
        string topic;
        RVO::Vector3 pos;
        bool pos_set;
        int id;
        float time;
        RVO::Vector3 pref_vel;

    public:
        ~PoseSubscriber() {};
        PoseSubscriber() {};
        PoseSubscriber(ros::NodeHandle, RVO::RVOSimulator *, string);
        void start();
        void callback(geometry_msgs::PoseStamped ps);
        void set_pref_vel(RVO::Vector3);
        void set_pref_vel(geometry_msgs::Twist);
        int get_id();
};

#endif