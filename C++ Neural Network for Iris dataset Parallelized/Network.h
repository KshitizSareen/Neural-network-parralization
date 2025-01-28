#ifndef NETWORK_H  // Include guard to prevent multiple inclusions
#define NETWORK_H
#include "vector"
#include "Neuron.h"
#include "Eigen/Dense"
using namespace Eigen;
using namespace std;

class Network{
    private:
        vector<vector<shared_ptr<Neuron>>> layers;
        double learningRate;
    public:
        Network();
        void AddLayer(int numberOfNeurons);

        void initializeLayerInput(const vector<double> &input);

        MatrixXd calculateWeightMatrix(const vector<shared_ptr<Neuron>> &prevLayer);

        MatrixXd calculateBiasMatrix(const vector<shared_ptr<Neuron>> &currentLayer);

        MatrixXd getActivationValues(const vector<shared_ptr<Neuron>> &layer);

        void forwardPropagate();

        void backwardPropagate(double outputValue);

        void adjustWeightsAndBiases(shared_ptr<Neuron> &neuron, double error);

        void updateWeightsAndBiases();

        void trainNetwork(vector<double> input,double outputValue);

        double testNetwork(vector<double> input,double outputValue);

        vector<double> getOutput(vector<double> input);

        double sigmoidDerivativeValue(double input);

        double costDerivativeValue(double predictedValue,double outputValue,int numberOfOutputs);

        double calculateErrorForLastNeuron(shared_ptr<Neuron> neuron,double outputValue,int numberOfOutputs);

        void adjustWeight(double errorValue,shared_ptr<Weight> weight,double learningRate);

        void adjustBias(double errorValue,shared_ptr<Neuron> neuron);
        
        double getLearningRate();

        void setLearningRate(double learningRate);

        double calculateErrorForHiddenLayer(shared_ptr<Neuron> neuron);
};

#endif