#include <bits/stdc++.h>
#include <iostream>
#include"include/Set.h"

using namespace std;

string parseHtml(const string& html)
{
    string content;
    string tag;

    bool insideTag = false;
    bool skipContent = false;

    
    Set<string> skipTags;

    skipTags.insert("script");
    skipTags.insert("style");
    skipTags.insert("head");
    skipTags.insert("noscript");
    skipTags.insert("meta");
    skipTags.insert("link");
    skipTags.insert("title");

    for (size_t i = 0; i < html.size(); i++)
    {
        if (html[i] == '<')
        {
            insideTag = true;
            tag.clear();

            i++;

            bool closing = false;

            if (i < html.size() && html[i] == '/')
            {
                closing = true;
                i++;
            }

            while (i < html.size() &&
                   html[i] != '>' &&
                   !isspace((unsigned char)html[i]))
            {
                tag += (char)tolower((unsigned char)html[i]);
                i++;
            }

            while (i < html.size() && html[i] != '>')
                i++;

            if (skipTags.exists(tag))
            {
                if (closing)
                    skipContent = false;
                else
                    skipContent = true;
            }

            insideTag = false;

            if (!content.empty() && content.back() != ' ')
                content += ' ';

            continue;
        }

        if (insideTag || skipContent)
            continue;

        if (isspace((unsigned char)html[i]))
        {
            if (!content.empty() && content.back() != ' ')
                content += ' ';
        }
        else
        {
            content += html[i];
        }
    }

    return content;
}

int main(){
    string s=R"HTML(<html lang="en"><head>
    <meta charset="UTF-8">
    <link rel="icon" type="image/svg+xml" href="/weblogo.png">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Nilesh</title>
    <script type="module" crossorigin="" src="/assets/index-BuXvdCp-.js"></script>
    <link rel="stylesheet" crossorigin="" href="/assets/index-CtWcEK9A.css">
  </head>
  <body>
    <div id="root"><div class="relative text-white"><canvas class="fixed inset-0 -z-10 bg-black" width="758" height="482"></canvas><div class="relative z-10"><nav class="fixed w-full px-4 sm:px-6 md:px-10 py-4 md:py-6 flex justify-between items-center backdrop-blur-md bg-black/40 border-b border-white/10 z-50"><h1 class="text-lg sm:text-xl font-bold">Nilesh<span class="text-cyan-400">.</span></h1><div class="hidden md:flex space-x-8 text-sm"><a href="#about" class="hover:text-cyan-400 transition">About</a><a href="#education" class="hover:text-cyan-400 transition">Education</a><a href="#skills" class="hover:text-cyan-400 transition">Skills</a><a href="#projects" class="hover:text-cyan-400 transition">Projects</a><a href="#certifications" class="hover:text-cyan-400 transition">Certifications</a><a href="#currently-learning" class="hover:text-cyan-400 transition">Exploring</a><a href="#contact" class="hover:text-cyan-400 transition">Contact</a></div><div class="md:hidden"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-menu cursor-pointer" aria-hidden="true"><path d="M4 5h16"></path><path d="M4 12h16"></path><path d="M4 19h16"></path></svg></div></nav><section class="min-h-screen flex flex-col md:flex-row items-center justify-center md:justify-between px-4 sm:px-6 md:px-12 pt-28 md:pt-40 gap-10"><div class="flex-1 flex justify-center md:justify-end order-1 md:order-2" style="opacity: 0; transform: translateX(27.3849px);"><div class="relative"><div class="absolute inset-0 rounded-full bg-cyan-400 blur-3xl opacity-30"></div><img alt="Nilesh" class="relative 
              w-32 h-32 


              
              sm:w-40 sm:h-40 
              md:w-80 md:h-80 
              object-cover rounded-full border-4 border-cyan-400 shadow-2xl" src="/images/Nilesh.jpg"></div></div><div class="flex-1 text-center md:text-left order-2 md:order-1" style="opacity: 0; transform: translateX(-27.3849px);"><h2 class="text-2xl sm:text-3xl md:text-6xl font-bold leading-tight">Hi, I'm <br><span class="text-cyan-400">Nilesh Sahu</span></h2><p class="mt-4 sm:mt-6 text-gray-400 text-sm sm:text-base md:text-lg max-w-xs sm:max-w-sm md:max-w-lg mx-auto md:mx-0">Full Stack Developer passionate about building scalable web applications and impactful digital solutions.</p><div class="flex justify-center md:justify-start gap-4 sm:gap-6 mt-6 text-gray-400"><a href="https://github.com/nscoded" target="_blank" rel="noopener noreferrer" class="hover:text-cyan-400 transition hover:scale-110"><svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-github" aria-hidden="true"><path d="M15 22v-4a4.8 4.8 0 0 0-1-3.5c3 0 6-2 6-5.5.08-1.25-.27-2.48-1-3.5.28-1.15.28-2.35 0-3.5 0 0-1 0-3 1.5-2.64-.5-5.36-.5-8 0C6 2 5 2 5 2c-.3 1.15-.3 2.35 0 3.5A5.403 5.403 0 0 0 4 9c0 3.5 3 5.5 6 5.5-.39.49-.68 1.05-.85 1.65-.17.6-.22 1.23-.15 1.85v4"></path><path d="M9 18c-4.51 2-5-2-7-2"></path></svg></a><a href="https://linkedin.com/in/nilesh2005" target="_blank" rel="noopener noreferrer" class="hover:text-cyan-400 transition hover:scale-110"><svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-linkedin" aria-hidden="true"><path d="M16 8a6 6 0 0 1 6 6v7h-4v-7a2 2 0 0 0-2-2 2 2 0 0 0-2 2v7h-4v-7a6 6 0 0 1 6-6z"></path><rect width="4" height="12" x="2" y="9"></rect><circle cx="4" cy="4" r="2"></circle></svg></a><a href="https://leetcode.com/NsCoded" target="_blank" rel="noopener noreferrer" class="hover:text-cyan-400 transition hover:scale-110"><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" class="w-5 h-5"><path d="M13.483 0a1.5 1.5 0 00-1.06.44l-9.9 9.9a1.5 1.5 0 000 2.12l9.9 9.9a1.5 1.5 0 002.12-2.12L6.663 12l7.84-7.84A1.5 1.5 0 0013.483 0z"></path></svg></a><a href="mailto:nileshsahu2005@gmail.com" class="hover:text-cyan-400 transition hover:scale-110"><svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-mail" aria-hidden="true"><path d="m22 7-8.991 5.727a2 2 0 0 1-2.009 0L2 7"></path><rect x="2" y="4" width="20" height="16" rx="2"></rect></svg></a></div></div></section><section id="about" class="min-h-screen flex items-center justify-center px-4 sm:px-6 md:px-10 py-16 sm:py-20 md:py-24"><div class="max-w-3xl text-center" style="opacity: 0; transform: translateY(60px);"><h2 class="text-2xl sm:text-3xl md:text-4xl font-bold text-cyan-400 mb-6 sm:mb-8">About Me</h2><p class="text-gray-300 leading-relaxed text-base sm:text-lg mb-5 sm:mb-6">I'm a <span class="text-white font-semibold">B.Tech Computer Science</span> student passionate about building real-world digital solutions. I enjoy working on scalable systems and interactive web applications.</p><p class="text-gray-400 leading-relaxed text-sm sm:text-base">My focus lies on mastering  <span class="text-cyan-400">Data Structure and Algorithms.</span> I have hands on knowledge of the  <span class="text-cyan-400">MERN Stack</span> and backend architecture. I am currently exploring  <span class="text-red-300">Cloud Computing services</span> and <span class="text-red-300">Cybersecurity</span> to broaden my technical expertise.</p></div></section><section id="education" class="min-h-screen px-10 py-24"><h2 class="text-4xl font-bold text-cyan-400 text-center mb-16">Education Journey</h2><div class="relative border-l-2 border-cyan-400 ml-4"><div class="mb-16 ml-8" style="opacity: 0; transform: translateX(-80px);"><div class="absolute -left-[9px] mt-8 w-4 h-4 bg-cyan-400 rounded-full shadow-lg shadow-cyan-400/50"></div><div class="bg-white/5 backdrop-blur-md p-6 rounded-2xl border border-white/10 hover:border-cyan-400 transition flex items-start gap-6"><img alt="logo" class="w-16 h-16 object-contain rounded-lg bg-white p-2" src="/logos/littleflower.jpg"><div><span class="text-cyan-300 text-sm font-semibold">2020 – 2021</span><h3 class="text-xl font-bold mt-1">Secondary School (10th)</h3><p class="text-gray-300 text-sm mt-1">Little Flower Hr Sec School, Raipur (CBSE)</p><p class="text-gray-400 text-sm mt-3">Completed 10th under CBSE Board with strong foundation in Mathematics and Science.</p><p class="text-gray-400 text-sm mt-3">Scored - 80%</p></div></div></div><div class="mb-16 ml-8" style="opacity: 0; transform: translateX(-80px);"><div class="absolute -left-[9px] mt-8 w-4 h-4 bg-cyan-400 rounded-full shadow-lg shadow-cyan-400/50"></div><div class="bg-white/5 backdrop-blur-md p-6 rounded-2xl border border-white/10 hover:border-cyan-400 transition flex items-start gap-6"><img alt="logo" class="w-16 h-16 object-contain rounded-lg bg-white p-2" src="/logos/littleflower.jpg"><div><span class="text-cyan-300 text-sm font-semibold">2022 – 2023</span><h3 class="text-xl font-bold mt-1">Senior Secondary (12th) – PCM + CS</h3><p class="text-gray-300 text-sm mt-1">Little Flower Hr Sec School, Raipur (CBSE)</p><p class="text-gray-400 text-sm mt-3">Studied Physics, Chemistry, Mathematics and Computer Science.</p><p class="text-gray-400 text-sm mt-3">Scored - 70%</p></div></div></div><div class="mb-16 ml-8" style="opacity: 0; transform: translateX(-80px);"><div class="absolute -left-[9px] mt-8 w-4 h-4 bg-cyan-400 rounded-full shadow-lg shadow-cyan-400/50"></div><div class="bg-white/5 backdrop-blur-md p-6 rounded-2xl border border-white/10 hover:border-cyan-400 transition flex items-start gap-6"><img alt="logo" class="w-16 h-16 object-contain rounded-lg bg-white p-2" src="/logos/ssipmt.jpg"><div><span class="text-cyan-300 text-sm font-semibold">2023 – 2027</span><h3 class="text-xl font-bold mt-1">B.Tech – Computer Science &amp; Engineering</h3><p class="text-gray-300 text-sm mt-1">Shri Shankaracharya Institute of Professional Management and Technology, Raipur</p><p class="text-gray-400 text-sm mt-3">Currently pursuing B.Tech with focus on Data Structures, Algorithms and Full Stack Development.</p><p class="text-gray-400 text-sm mt-3">Current CGPA - 7.63</p></div></div></div></div></section><section id="skills" class="relative min-h-screen overflow-hidden px-6 md:px-10 py-20"><h2 class="text-3xl md:text-4xl font-bold text-center text-cyan-400 mb-16">Skills</h2><div class="grid grid-cols-2 gap-4 max-w-md mx-auto"><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">React</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">Node.js</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">Express</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">MySQL</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">C++</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">Java</div><div class="bg-white/10 text-gray-300 text-sm py-3 rounded-lg text-center">Onshape</div></div></section><section id="projects" class="min-h-screen px-10 py-24 relative"><h2 class="text-4xl font-bold text-center text-cyan-400 mb-16">Projects</h2><div class="grid md:grid-cols-3 gap-10"><a href="https://doctor-appointment-booking-system-lilac.vercel.app/" target="_blank" rel="noopener noreferrer" class="
    group
    bg-white/5 backdrop-blur-md
    p-8 rounded-2xl
    border border-white/10
    transition-all duration-300
    flex flex-col items-center text-center
    hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/30 cursor-pointer
  " style="opacity: 0; transform: translateY(60px);"><img alt="logo" class="w-16 h-16 object-contain mb-6 bg-white rounded-lg p-2" src="/logos/DABS.png"><h3 class="text-xl font-semibold text-white mb-4 group-hover:text-cyan-300 transition">Doctor Appointment Booking System</h3><p class="text-gray-400 text-sm leading-relaxed">A full-featured appointment management platform where users can book doctor appointments and admins can manage hospitals and doctors efficiently.</p></a><a href="https://samadhan.ssipmt.in" target="_blank" rel="noopener noreferrer" class="
    group
    bg-white/5 backdrop-blur-md
    p-8 rounded-2xl
    border border-white/10
    transition-all duration-300
    flex flex-col items-center text-center
    hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/30 cursor-pointer
  " style="opacity: 0; transform: translateY(60px);"><img alt="logo" class="w-16 h-16 object-contain mb-6 bg-white rounded-lg p-2" src="/logos/samadhan.jpeg"><h3 class="text-xl font-semibold text-white mb-4 group-hover:text-cyan-300 transition">Samadhan – Government Complaint Management System</h3><p class="text-gray-400 text-sm leading-relaxed">A centralized grievance monitoring dashboard developed for the Government of Chhattisgarh to track public complaints.</p></a><a href="https://lyfta-pi.vercel.app/" target="_blank" rel="noopener noreferrer" class="
    group
    bg-white/5 backdrop-blur-md
    p-8 rounded-2xl
    border border-white/10
    transition-all duration-300
    flex flex-col items-center text-center
    hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/30 cursor-pointer
  " style="opacity: 0; transform: translateY(60px);"><img alt="logo" class="w-16 h-16 object-contain mb-6 bg-white rounded-lg p-2" src="/logos/lyfta.png"><h3 class="text-xl font-semibold text-white mb-4 group-hover:text-cyan-300 transition">Lyfta Fitness Analytics Dashboard</h3><p class="text-gray-400 text-sm leading-relaxed">Built a modern fitness dashboard using Lyfta API to display my workouts and track my streak progress.</p></a><div class="
    group
    bg-white/5 backdrop-blur-md
    p-8 rounded-2xl
    border border-white/10
    transition-all duration-300
    flex flex-col items-center text-center
    
  " style="opacity: 0; transform: translateY(60px);"><h3 class="text-xl font-semibold text-white mb-4 group-hover:text-cyan-300 transition">NPWT Device Monitoring System</h3><p class="text-gray-400 text-sm leading-relaxed">An IoT-based monitoring system for managing medical device operations with real-time tracking.</p><span class="
                    mt-8 inline-block
                    text-xs
                    bg-cyan-400/20 text-cyan-300
                    px-4 py-1.5 rounded-full
                    border border-cyan-400/30
                    transition-all duration-300
                    group-hover:bg-red-300
                    group-hover:text-black
                    group-hover:scale-105
                  ">IN PROGRESS...</span></div></div></section><section id="certifications" class="min-h-screen px-6 sm:px-8 md:px-10 py-16 sm:py-20 md:py-24"><h2 class="text-3xl sm:text-4xl font-bold text-cyan-400 text-center mb-12 sm:mb-16">Certifications</h2><div class="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 sm:gap-8"><a href="https://drive.google.com/file/d/159kLTlF9giujN1OLb47Ig0EHMK_h2lDv/view?usp=sharing" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/vectre.jpg"><h3 class="text-lg sm:text-xl font-semibold">MERN Stack Web Development</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">Vectre Consultancy Pvt Ltd • 2024</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Completed full stack development training covering React, Node.js and MySQL.</p></a><a href="https://drive.google.com/file/d/1mvqU49t9kCHzUWLkJZDeq-QYzJ8Fg3Mv/view?usp=sharing" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/Devtown.jpg"><h3 class="text-lg sm:text-xl font-semibold">Competitive Programming</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">DevTown • 2024</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Strengthened problem-solving skills and understanding of core algorithms.</p></a><a href="https://drive.google.com/file/d/1VcebEwdBlgoTyw9q8BEs8vW-9B6lIyEC/view?usp=sharing" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/Devtown.jpg"><h3 class="text-lg sm:text-xl font-semibold">C++ Programming</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">DevTown • 2024</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Built strong foundation in object-oriented programming using C++.</p></a><a href="https://drive.google.com/file/d/11yJSaYoxW1gLrpQPCs6K-UA-pZIB3yr6/view?usp=sharing" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/govt.png"><h3 class="text-lg sm:text-xl font-semibold">Project Completion Certificate</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">Government of Chhattisgarh • 2025</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Awarded by the District Collector, Raipur for significant contribution to district-level government software development projects.</p></a><a href="https://verify.skilljar.com/c/rwptnww7a7cn" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/zscaler.png"><h3 class="text-lg sm:text-xl font-semibold">Zscaler Zero Trust Associate (ZTCA) Certification</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">Zscaler Academy • 2026</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Earned the Zscaler Zero Trust Associate (ZTCA) certification from Zscaler Academy by successfully clearing the certification exam, demonstrating strong understanding of Zero Trust architecture and secure access principles.</p></a><a href="https://verify.skilljar.com/c/m3f8ajvakktk" target="_blank" rel="noopener noreferrer" class="bg-white/5 backdrop-blur-md p-6 sm:p-8 rounded-2xl border border-white/10 hover:border-cyan-400 hover:shadow-lg hover:shadow-cyan-400/20 transition-all duration-300 flex flex-col items-center text-center" style="opacity: 0; transform: translateY(40px);"><img alt="logo" class="w-14 h-14 sm:w-16 sm:h-16 object-contain mb-4 bg-white rounded-lg p-2" src="/logos/zscaler.png"><h3 class="text-lg sm:text-xl font-semibold">Fundamentals of Cybersecurity (EDU-102)</h3><p class="text-cyan-300 text-xs sm:text-sm mt-1">Zscaler Training • 2026</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Completed the 'Fundamentals of Cybersecurity (EDU-102)' course offered by Zscaler Training.</p></a></div></section><section id="currently-learning" class="min-h-screen px-10 py-24"><h2 class="text-4xl font-bold text-cyan-400 text-center mb-16">Currently Exploring</h2><div class="grid md:grid-cols-2 gap-12"><a href="https://aws.amazon.com/training/awsacademy/" target="_blank" rel="noopener noreferrer" class="
              group relative
              bg-white/5 backdrop-blur-md
              border border-white/10
              p-8 rounded-2xl
              transition-all duration-300
              flex gap-6 items-start
              cursor-pointer
            " style="opacity: 0; transform: translateY(60px);"><span class="
                absolute top-4 right-4 text-xs 
                bg-cyan-400/20 text-cyan-300 
                px-3 py-1 rounded-full 
                border border-cyan-400/40 
                transition-all duration-300
                group-hover:scale-110
                group-hover:bg-red-300
                group-hover:text-black
              ">IN PROGRESS</span><img alt="logo" class="w-16 h-16 object-contain bg-white rounded-lg" src="/logos/awscloud.png"><div><h3 class="text-xl font-semibold text-cyan-300">AWS Academy Cloud Foundations</h3><p class="text-gray-400 text-sm mt-1">AWS Academy • 2025</p><p class="text-gray-400 text-sm mt-4 leading-relaxed">Currently enrolled in the AWS Academy Cloud Foundations course, gaining a foundational understanding of cloud computing concepts including cloud principles, AWS core services, security, architecture and support.</p></div></a></div></section><section id="contact" class="min-h-screen flex flex-col justify-center items-center px-6 py-24"><h2 class="text-4xl font-bold text-cyan-400 mb-4 text-center">Links And Connections</h2><p class="text-gray-400 text-center max-w-xl mb-12">See my progress and connect wit me</p><div class="grid md:grid-cols-2 gap-6 w-full max-w-3xl"><a href="https://github.com/nscoded" target="_blank" rel="noopener noreferrer" class="
              group
              flex items-center gap-4
              bg-white/5 backdrop-blur-md
              px-5 py-4
              rounded-xl
              border border-white/10
              hover:border-cyan-400
              transition-all duration-300
            "><img alt="GitHub" class="
                w-10 h-10
                rounded-full
                object-cover
                bg-white
                p-1
                group-hover:scale-110
                transition duration-300
              " src="/logos/github.png"><div class="flex flex-col"><span class="text-white font-medium group-hover:text-cyan-400 transition">GitHub</span><span class="text-gray-400 text-sm">Open Source &amp; Projects</span></div></a><a href="https://linkedin.com/in/nilesh2005" target="_blank" rel="noopener noreferrer" class="
              group
              flex items-center gap-4
              bg-white/5 backdrop-blur-md
              px-5 py-4
              rounded-xl
              border border-white/10
              hover:border-cyan-400
              transition-all duration-300
            "><img alt="LinkedIn" class="
                w-10 h-10
                rounded-full
                object-cover
                bg-white
                p-1
                group-hover:scale-110
                transition duration-300
              " src="/logos/linkedin.png"><div class="flex flex-col"><span class="text-white font-medium group-hover:text-cyan-400 transition">LinkedIn</span><span class="text-gray-400 text-sm">Professional Network</span></div></a><a href="https://leetcode.com/NsCoded" target="_blank" rel="noopener noreferrer" class="
              group
              flex items-center gap-4
              bg-white/5 backdrop-blur-md
              px-5 py-4
              rounded-xl
              border border-white/10
              hover:border-cyan-400
              transition-all duration-300
            "><img alt="LeetCode" class="
                w-10 h-10
                rounded-full
                object-cover
                bg-white
                p-1
                group-hover:scale-110
                transition duration-300
              " src="/logos/leetcode.png"><div class="flex flex-col"><span class="text-white font-medium group-hover:text-cyan-400 transition">LeetCode</span><span class="text-gray-400 text-sm">Problem Solving</span></div></a><a href="https://www.duolingo.com/profile/Nilesh070501" target="_blank" rel="noopener noreferrer" class="
              group
              flex items-center gap-4
              bg-white/5 backdrop-blur-md
              px-5 py-4
              rounded-xl
              border border-white/10
              hover:border-cyan-400
              transition-all duration-300
            "><img alt="Duolingo" class="
                w-10 h-10
                rounded-full
                object-cover
                bg-white
                p-1
                group-hover:scale-110
                transition duration-300
              " src="/logos/duolingo.png"><div class="flex flex-col"><span class="text-white font-medium group-hover:text-cyan-400 transition">Duolingo</span><span class="text-gray-400 text-sm">Language Learning</span></div></a><a href="https://lyfta.app/profile/user/6hp0d" target="_blank" rel="noopener noreferrer" class="
              group
              flex items-center gap-4
              bg-white/5 backdrop-blur-md
              px-5 py-4
              rounded-xl
              border border-white/10
              hover:border-cyan-400
              transition-all duration-300
            "><img alt="Lyfta" class="
                w-10 h-10
                rounded-full
                object-cover
                bg-white
                p-1
                group-hover:scale-110
                transition duration-300
              " src="/logos/lyfta.png"><div class="flex flex-col"><span class="text-white font-medium group-hover:text-cyan-400 transition">Lyfta</span><span class="text-gray-400 text-sm">Workout Profile</span></div></a></div></section><footer class="bg-[#0b0f19] border-t border-white/10 py-6 px-6"><div class="max-w-6xl mx-auto flex flex-col md:flex-row justify-between items-center gap-6"><div class="text-center md:text-left"><h3 class="text-white font-medium text-base">Nilesh Sahu</h3><p class="text-gray-400 text-xs">Full Stack Developer • Raipur, India</p></div><div class="flex items-center bg-white/5 border border-white/10 rounded-full overflow-hidden"><input placeholder="Write a quick message..." class="
              bg-transparent
              text-white
              text-xs
              px-4 py-2
              outline-none
              w-48
              placeholder-gray-500
            " type="text" value=""><button class="
              bg-cyan-500
              hover:bg-cyan-600
              text-black
              text-xs
              px-4 py-2
              transition
            ">Send</button></div><div class="text-center md:text-right text-xs text-gray-400"><p class="text-white font-medium">Location</p><p>Raipur, Chhattisgarh, India</p></div></div><div class="mt-4 text-center text-gray-500 text-[11px]">© 2026 Nilesh Sahu</div></footer></div></div></div>
  

</body></html>)HTML";

    string result=parseHtml(s);
    cout<<result<<endl;
    cout<<s.size()<<endl;
    cout<<result.size()<<endl;

}