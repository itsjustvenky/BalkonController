/*
 * ControllerNode.h
 *
 *  Created on: 16.05.2016
 *      Author: ian
 */

#ifndef SRC_CONTROLLERNODE_H_
#define SRC_CONTROLLERNODE_H_

#include <HomieNode.hpp>

class ControllerNode: public HomieNode {

	// MQTT-Property Strings for ControllerNode
	enum Properties {Mode, State, Pumpe, MainValve, LAST_Prop};
	const String PropString[LAST_Prop] = {"Mode", "State", "Pumpe", "MainValve"};

	// MQTT-Identifier for Property 'Mode'
	enum Modes {Invalid=-1, Manual=0, Full_Auto, OneRun, Off, Last_Mode};
	const char mode_char[Last_Mode] = { 'm', 'a', '1', '0' };

private:
	Modes mode;
	Modes mode_1run_saved_state;
	bool pumpe;
	bool valve;

	bool setMode(String const & value);
	bool setPumpe(String const & value);
	bool setMainValve(String const & value);

	bool startOneRun();
    void PumpeSet(bool on);
    void ValveSet(bool on);

public:
	ControllerNode();

	virtual void loop();
	virtual void setup();
    virtual bool handleInput(const String  &property, const HomieRange& range, const String &value) override;

    void PumpeOn();
    void PumpeOff();
    void ValveOn();
    void ValveOff();


};

#endif /* SRC_CONTROLLERNODE_H_ */
